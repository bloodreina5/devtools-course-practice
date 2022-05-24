const http  = require('http');
const fs    = require('fs');
const axios = require('axios');
const { Octokit } = require("@octokit/core");
const { createAppAuth } = require("@octokit/auth-app");

const port = process.env.PORT || 80;

const installationOctokit = new Octokit({
    authStrategy: createAppAuth,
    auth: {
      appId: 202493,
      privateKey: process.env.PRIVATE_KEY,
      installationId: 25823314,
    },
});

async function checkReadiness(pull_id) {
    // Count number of unique approvers
    const result = await installationOctokit.request("GET /repos/{owner}/{repo}/pulls/{pull_id}/reviews", {
        owner: "UNN-ITMM-Software",
        repo: "devtools-course-practice",
        pull_id: pull_id,
    });

    let approvers = new Set();
    result.data.forEach(entry => {
        if (entry.state == 'APPROVED') {
            approvers.add(entry.user.login);
        }
    });

    if (approvers.size < 2)
        return;

    // Put a readiness label
    installationOctokit.request("POST /repos/{owner}/{repo}/issues/{pull_id}/labels", {
        owner: "UNN-ITMM-Software",
        repo: "devtools-course-practice",
        pull_id: pull_id,
        labels: ["Ready for merge"],
    });
}

http.createServer(function (req, res) {
    // Get JSON data for POST request
    let body = '';
    req.on('data', chunk => {
        body += chunk.toString();
    });
    req.on('end', () => {
        body = JSON.parse(body);
        
        if (body.review.state == "approved") {
            checkReadiness(body.pull_request.number);
        }

        res.end();
    });
}).listen(port);