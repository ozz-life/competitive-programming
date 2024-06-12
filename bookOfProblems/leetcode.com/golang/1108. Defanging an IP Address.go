func defangIPaddr(address string) string {
	var builder strings.Builder

	for i := range address {
		if address[i] == '.' {
			builder.WriteString("[.]")
		} else {
			builder.WriteByte(address[i])
		}
	}

	return builder.String()
}

func defangIPaddr(address string) string {
	result := []rune{}

	for _, v := range address {
		if v == '.' {
			result = append(result, '[', '.', ']')
		} else {
			result = append(result, v)
		}
	}

	return string(result)
}

func defangIPaddr(address string) string {
	var b bytes.Buffer

	for _, c := range address {
		if c == '.' {
			b.WriteString("[.]")
		} else {
			b.WriteRune(c)
		}
	}

	return b.String()
}

func defangIPaddr(address string) string {
	l := len(address)

	for i := 0; i < l; i++ {
		if address[i] == 46 {
			address = address[:i] + "[.]" + address[i+1:]
			fmt.Println(address[i+3])
			i = i + 3
			l = l + 2
		}
	}

	return address
}