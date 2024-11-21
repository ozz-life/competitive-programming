package kata

import (
	"strings"
	"strconv"
)

func ToCsvText(array [][]int) string {
	var sb strings.Builder

	for i, row := range array {
		for j, val := range row {
			sb.WriteString(strconv.Itoa(val))
			if j < len(row) - 1 {
				sb.WriteString(",")
			}
		}
		if i < len(array) - 1 {
			sb.WriteString("\n")
		}
	}

	return sb.String()
}

////////////////////////////////////////////////////////////////////////////////

package kata

import (
  "fmt"
  "strings"
)

func ToCsvText(array [][]int) string {

  lines := []string{}
  
  for _, line := range array {
    new_line := strings.Trim(fmt.Sprint(line), "[]")
    new_line = strings.ReplaceAll(new_line, " ", ",")
    lines = append(lines, new_line)
  }
  
  return strings.Join(lines, "\n")
}