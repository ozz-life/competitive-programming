https://github.com/EndlessCheng/codeforces-go/tree/master/copypasta

https://www.codementor.io/@tucnak/using-golang-for-competitive-programming-h8lhvxzt3
https://github.com/lorenzotinfena/goji/

Как готовиться: повторить базовые алгоритмы — сортировки, бинарный, два указател, жадный.
Так же полезно повторить: json, чтетие данных на SQL, postgreSQL.
Можно посмотреть литкод, кодфорсес, задачи, которые спрашивают на собеседованиях.




// Stack = slicing + append

// Queue = slicing + append (tho u can implement it yourself efficiently, using linked list for example, or using arrays but ensuring as less memory allocations as possible = circular queue)

// HashMap is great, HashSet is easy to implement and they are, on my opinion, are far more effective than STANDARD stl unordered_map/unordered_map. U can use standard Go map and 99% that no test will overload it to become inefficient, but in C++ there exists test cases to overload STANDARD hashmap and u need to write own implementation of hash function to make it efficient.

// LinkedList exists in Go.

// Heap also.

// Real troubles are only with interface{} in standard sorting, heap and others data structures, since it's eating precious nanoseconds during runtime. This is the reason why I implemented heap on my own and used code generation on contests to make heap much more effective (and it's really helped since some problems are restrictive on time even with optimal algorithm).

// Also, no BST in Go, and I think developers won't add them in standard library since it's too specific data structures. People that need them will implement them how they like. I used Treap (randomised BST), and it's pretty easy to understand and implement

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

// #endregion

// #region USEFUL FUNCTIONS

// Variations:
// Sli(): empty slice
// Sli(n): slice with size n
// Sli(n, c): Slice with size n and capacity c
func Sli[T any](args ...int) []T {
	switch len(args) {
	case 0:
		return []T{}
	case 1:
		return make([]T, args[0])
	case 2:
		return make([]T, args[0], args[1])
	}
	panic("Sli invalid args")
}

// Variations:
// Slint(): empty slice
// Slint(n): slice with size n
// Slint(n, c): Slice with size n and capacity c
func Slint(args ...int) []int {
	switch len(args) {
	case 0:
		return []int{}
	case 1:
		return make([]int, args[0])
	case 2:
		return make([]int, args[0], args[1])
	}
	panic("Sli invalid args")
}

// #endregion