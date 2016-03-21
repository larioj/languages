object Main {
  def main(args: Array[String]): Unit = {
    def max(a: Int, b: Int): Int = {
      return if (a > b) a else b
    }
    println(max(1, 2))
  }
}
