//O(n*log(log(n)))
func SieveOfEratosthenes(n int) []int {
	prime := make([]bool, n+1)
	for i := range prime {
		prime[i] = true
	}
	prime[0], prime[1] = false, false

	for i := 2; i*i <= n; i++ {
		if prime[i] {
			for j := i * i; j <= n; j += i {
				prime[j] = false
			}
		}
	}

	var primes []int
	for i := 2; i <= n; i++ {
		if prime[i] {
			primes = append(primes, i)
		}
	}

	return primes
}

func SieveOfLinearEratosthenes(n int) ([]int, []int) {
	lp := make([]int, n+1) // Массив минимальных простых делителей
	pr := []int{}           // Срез для хранения простых чисел

	for i := 2; i <= n; i++ {
		if lp[i] == 0 { // Если i - простое число
			lp[i] = i
			pr = append(pr, i)
		}
		for j := 0; j < len(pr) && i*pr[j] <= n; j++ {
			lp[i*pr[j]] = pr[j]
			if pr[j] == lp[i] {
				break
			}
		}
	}

	return pr, lp
}