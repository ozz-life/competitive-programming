package kata

func Solution(a, b string) string {
  var short, long string
  var sb string.Builder
  
  if len(a) < len(b) {
    short = a
    long = b
  } else {
    short = b
    long = a
  }
  
  sb = short + long + short
  
  return sb
}

////////////////////////////////////////////////////////////////////////////////

package kata

func Solution(a, b string) string {
  if len(a) < len(b) {
    return a + b + a
  }
  return b + a + b
}

////////////////////////////////////////////////////////////////////////////////