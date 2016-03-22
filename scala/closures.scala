object Main {
  def main(args: Array[String]): Unit = {
    var more = 0
    def addMore(x: Int): Int = x + more
    println(addMore(2))
    more = 20
    println(addMore(2))
  }
}
