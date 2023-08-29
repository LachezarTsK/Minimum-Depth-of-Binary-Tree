
/*
 Function Node is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function (root) {
    if (root === null) {
        return 0;
    }

    //const {Queue} = require('@datastructures-js/queue');
    //Queue<TreeNode>
    const queue = new Queue();
    queue.enqueue(root);

    let depthLevel = 0;
    let leafNodeFound = false;

    while (!queue.isEmpty() && !leafNodeFound) {
        ++depthLevel;
        let nodesInDepthLevel = queue.size();

        while (nodesInDepthLevel-- > 0) {
            const current = queue.dequeue();
            if (isLeafNode(current)) {
                leafNodeFound = true;
                break;
            }
            if (current.left !== null) {
                queue.enqueue(current.left);
            }
            if (current.right !== null) {
                queue.enqueue(current.right);
            }
        }
    }
    return depthLevel;
};

/**
 * @param {TreeNode} node
 * @return {boolean}
 */
function isLeafNode(node) {
    return node.left === null && node.right === null;
}
