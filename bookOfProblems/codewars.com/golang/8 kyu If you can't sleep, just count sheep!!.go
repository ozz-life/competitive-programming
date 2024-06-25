package kata

import (
	"strings"
	"strconv"
)

// countSheep takes an integer num and returns a string counting sheep up to num
func countSheep(num int) string {
	var sb strings.Builder

	for i := 1; i <= num; i++ {
		sb.WriteString(strconv.Itoa(i))
		sb.WriteString(" sheep...")
	}

	return sb.String()
}

////////////////////////////////////////////////////////////////////////////////

package kata

import (
  "fmt"
  "strings"
)

func countSheep(num int) string {
  var sb strings.Builder

  for count := 1; count <= num; count++ {
        fmt.Fprintf(&sb, "%d sheep...", count)
  }
  
  return sb.String()
}