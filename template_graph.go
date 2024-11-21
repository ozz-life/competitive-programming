package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

const maxSz = 100000

var g [maxSz][]int
var vis [maxSz]bool
var level [maxSz]int

func main() {
	defer out.Flush()
	var n, m int
	fmt.Fscanf(in, "%d %d\n", &n, &m)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscanf(in, "%d %d\n", &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	var src int
	fmt.Fscanf(in, "%d\n", &src)
	dfs(src)
}

func dfs(u int) {
	vis[u] = true
	for _, v := range g[u] {
		if !vis[v] {
			level[v] = 1 + level[u]
			dfs(v)
		}
	}
}
