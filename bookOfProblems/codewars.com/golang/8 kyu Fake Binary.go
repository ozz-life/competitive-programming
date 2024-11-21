package kata

func FakeBin(x string) string {
    result := make([]byte, len(x))

    for i, ch := range x {
        if ch < '5' {
            result[i] = '0'
        } else {
            result[i] = '1'
        }
    }

    return string(result)
}

////////////////////////////////////////////////////////////////////////////////

package kata


func FakeBin(x string) (result string) {
    for _, char := range x {
        if char < '5' {
            result += "0"
        } else {
            result += "1"
        }
    }
    return
}