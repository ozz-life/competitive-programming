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
          Author: Stanislav "Oz" Ozeransky | Site: https:://ozz.life/

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

type IO struct {
	r *bufio.Reader
	w *bufio.Writer
}

func (io *IO) ScanInt8() (x int8)   { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt16() (x int16) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt32() (x int32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanInt() (x int)     { fmt.Fscan(io.r, &x); return }
 
func (io *IO) ScanUInt8() (x uint8)   { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt16() (x uint16) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt32() (x uint32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanUInt() (x uint)     { fmt.Fscan(io.r, &x); return }
 
func (io *IO) ScanFloat32() (x float32) { fmt.Fscan(io.r, &x); return }
func (io *IO) ScanFloat64() (x float64) { fmt.Fscan(io.r, &x); return }
 
func (io *IO) ScanString() (x string) { fmt.Fscan(io.r, &x); return }
 
func (io *IO) Flush() { io.w.Flush() }

/*
 * Solve
 ******************************************************************************/

func solve(in *bufio.Reader, out *bufio.Writer) {
	var a, b int
	fmt.Fscan(in, &a, &b)

	sum := a + b

	fmt.Fprintln(out, sum)
}

/*
 * Main
 ******************************************************************************/

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// count_test := 1
	var count_test int
	fmt.Fscan(in, &count_test)

	for i := 0; i < count_test; i++ {
		solve(in, out)
	}
}
