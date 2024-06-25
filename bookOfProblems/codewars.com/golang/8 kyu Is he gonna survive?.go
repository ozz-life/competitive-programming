package kata

func Hero(bullets, dragons int) bool {
  return bullets >= 2*dragons
}

////////////////////////////////////////////////////////////////////////////////

package kata

const BULLETS_PER_DRAGON = 2

func Hero(bullets, dragons int) bool {
  return (bullets / BULLETS_PER_DRAGON) >= dragons
}