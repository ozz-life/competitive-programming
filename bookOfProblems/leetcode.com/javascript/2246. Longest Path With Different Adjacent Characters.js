/**
 * @param {number[]} parent
 * @param {string} s
 * @return {number}
 */
var longestPath = function (parent, s) {
    let longestPath = 1; // Initialize return value for longest path
    const graph = new Map(); // Initialize map for graph
    for (let i = 1; i < parent.length; i++) { // Loop 0-indexed array
        if (!graph.has(parent[i])) graph.set(parent[i], []); // Initialize empty array if undefined
        graph.get(parent[i]).push(i); // Push value to array
    }

    const dfs = (current) => { // DFS algorithm
        if (!graph.has(current)) return 1; // Return 1 if not defined
        let longest = 0; // Initialize longest variable
        let secondLongest = 0; // Initialize second longest variable
        for (const child of graph.get(current)) { // Loop childs of current node
            const longestFromChild = dfs(child); // Get longest from child
            if (s[current] != s[child]) { // Check if node have different characters
                if (longestFromChild > longest) { // Check if longestFromChild is bigger than current longest
                    secondLongest = longest; // Set longest to second longest
                    longest = longestFromChild; // Set longest to longestFromChild
                } else if (longestFromChild > secondLongest) { // Check if longestFromChild is bigger than secondLongest
                    secondLongest = longestFromChild; // Set secondLongest to longestFromChild
                }
            }
        }
        longestPath = Math.max(longestPath, longest + secondLongest + 1); // Set longest path 
        return longest + 1; // Return longest of current plus one
    }
    dfs(0); // Start DFS
    return longestPath; // Return longest path variable
};

////////////////////////////////////////////////////////////////////////////////

/**
 * @param {number[]} parent
 * @param {string} s
 * @return {number}
 */
var longestPath = function (parent, s) {
    let longestPath = 1;
    const graph = new Map();
    for (let i = 1; i < parent.length; i++) {
        if (!graph.has(parent[i])) graph.set(parent[i], []);
        graph.get(parent[i]).push(i);
    }

    const dfs = (current) => {
        if (!graph.has(current)) return 1; 
        let longest = 0;
        let secondLongest = 0;
        for (const child of graph.get(current)) { 
            const longestFromChild = dfs(child); 
            if (s[current] != s[child]) {
                if (longestFromChild > longest) {
                    secondLongest = longest;
                    longest = longestFromChild;
                } else if (longestFromChild > secondLongest) {
                    secondLongest = longestFromChild;
                }
            }
        }
        longestPath = Math.max(longestPath, longest + secondLongest + 1);
        return longest + 1;
    }
    dfs(0);
    return longestPath;
};
