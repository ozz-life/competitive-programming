// Ну есть 2 способа.
// 1. Неправильный
// Почитай стандартную библиотеку. Есть такой big.Int https://pkg.go.dev/math/big@go1.22.4#Int.SetBit
// И Add там тоже есть.
// Так себе удовольствие с этим возиться, но можно.

// 2. Правильный. 
// Складываешь в столбик как в школе учили. Справа налево, с переносом переполнения


// WA: слишком большие числа
func addBinary(a string, b string) string {
	numA, err := strconv.ParseInt(a, 2, 64)
	if err != nil {
		fmt.Println("Ошибка при преобразовании строки a:", err)
		return ""
	}
	numB, err := strconv.ParseInt(b, 2, 64)
	if err != nil {
		fmt.Println("Ошибка при преобразовании строки b:", err)
		return ""
	}

	result := numA + numB
	resultString := strconv.FormatInt(result, 2)
	return resultString
}

// big.Int
func addBinary(a string, b string) string {
	aInt, bInt, sum := new(big.Int), new(big.Int), new(big.Int)
	aInt.SetString(a, 2)
	bInt.SetString(b, 2)
	sum.Add(aInt, bInt)

	return sum.Text(2)
}

func addBinary(a string, b string) string {
	num1, _ := new(big.Int).SetString(a, 2)
	num2, _ := new(big.Int).SetString(b, 2)
	num1.Add(num1, num2)
	return num1.Text(2)
}

////////////////////////////////////////////////////////////////////////////////

