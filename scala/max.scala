object Main {
  def main(args: Array[String]): Unit = {
    def mymax(a: Int, b: Int): Int = {
      return if (a > b) {
        a
      }
      else {
        b
      }
    }
    println(mymax(1, 2))
    println(1.max(2))
    println(1 max 2 max 4 max 8)
  }
}
