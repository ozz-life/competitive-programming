/*
            ▒█████  ▒███████▒▒███████▒      ██▓     ██▓  █████▒▓█████
           ▒██▒  ██▒▒ ▒ ▒ ▄▀░▒ ▒ ▒ ▄▀░     ▓██▒    ▓██▒▓██   ▒ ▓█   ▀
           ▒██░  ██▒░ ▒ ▄▀▒░ ░ ▒ ▄▀▒░      ▒██░    ▒██▒▒████ ░ ▒███
           ▒██   ██░  ▄▀▒   ░  ▄▀▒   ░     ▒██░    ░██░░▓█▒  ░ ▒▓█  ▄
           ░ ████▓▒░▒███████▒▒███████▒ ██▓ ░██████▒░██░░▒█░    ░▒████▒
           ░ ▒░▒░▒░ ░▒▒ ▓░▒░▒░▒▒ ▓░▒░▒ ▒▓▒ ░ ▒░▓  ░░▓   ▒ ░    ░░ ▒░ ░
             ░ ▒ ▒░ ░░▒ ▒ ░ ▒░░▒ ▒ ░ ▒ ░▒  ░ ░ ▒  ░ ▒ ░ ░       ░ ░  ░
           ░ ░ ░ ▒  ░ ░ ░ ░ ░░ ░ ░ ░ ░ ░     ░ ░    ▒ ░ ░ ░       ░
               ░ ░    ░ ░      ░ ░      ░      ░  ░ ░             ░  ░
                    ░        ░          ░
          Author: Stanislav "ozz" Ozeransky | Site: https:://ozz.life/

We are what we think.
All that we are arises with our thoughts.
With our thoughts we make the world.
Speak or act with a pure mind
And happiness will follow you
As your shadow, unshakable. ― Gautama Buddha

*/

package main

import (
	"bufio"
	"fmt"
	"os"
)

/*
 * Math
 ******************************************************************************/

func gcd(a, b int) int {
	for a != 0 {
		a, b = b%a, a
	}
	return b
}
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}
func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

/*
 * Solve
 ******************************************************************************/

func solve(in *bufio.Reader, out *bufio.Writer) {
	var g1_1, g1_2, g2_1, g2_2 int // Голы команда_матч
	var guest_bool int             // 1 дома, 2 в гостях

	fmt.Fscanf(in, "%d:%d\n", &g1_1, &g2_1)
	fmt.Fscanf(in, "%d:%d\n", &g1_2, &g2_2)
	fmt.Fscanf(in, "%d", &guest_bool)

	goals_team1 := g1_1 + g1_2
	goals_team2 := g2_1 + g2_2

	// Гарантированная победа в обоих матчах
	if goals_team1 > goals_team2 {
		fmt.Fprintf(out, "0")
	} else {
		switch guest_bool {
		// дома
		case 1:
			if goals_team1 < goals_team2 {
				if g1_1 < g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1)
				} else if g1_1 == g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1+1)
				} else if g1_1 > g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1+1)
				}
			} else if goals_team1 == goals_team2 {
				if g1_1 < g2_2 {
					fmt.Fprintf(out, "0")
				} else if g1_1 == g2_2 {
					fmt.Fprintf(out, "1")
				} else if g1_1 > g2_2 {
					fmt.Fprintf(out, "1")
				}
			}
		// в гостях
		case 2:
			if goals_team1 < goals_team2 {
				if g1_1 < g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1+1)
				} else if g1_1 == g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1+1)
				} else if g1_1 > g2_2 {
					fmt.Fprintf(out, "%d", goals_team2-goals_team1)
				}
			} else if goals_team1 == goals_team2 {
				if g1_1 < g2_2 {
					fmt.Fprintf(out, "1")
				} else if g1_1 == g2_2 {
					fmt.Fprintf(out, "1")
				} else if g1_1 > g2_2 {
					fmt.Fprintf(out, "0")
				}
			}
		}
	}
}

/*
 * Main
 ******************************************************************************/

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// var count_test int
	// fmt.Fscan(in, &count_test)

	var count_test int = 1
	for i := 0; i < count_test; i++ {
		solve(in, out)
	}
}
