package kata

import (
	"strings"
)

func AbbrevName(name string) string {
	parts := strings.Split(name, " ")
	if len(parts) != 2 {
		return ""
	}

	firstInitial := strings.ToUpper(string(parts[0][0]))
	secondInitial := strings.ToUpper(string(parts[1][0]))

	initials := firstInitial + "." + secondInitial

	return initials
}

////////////////////////////////////////////////////////////////////////////////

package kata

import "strings"

func AbbrevName(name string) string{
  words := strings.Split(name, " ")
  return strings.ToUpper(string(words[0][0])) + "." + strings.ToUpper(string(words[1][0]))
}