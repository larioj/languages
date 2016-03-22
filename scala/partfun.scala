object Main {
  def main(args: Array[String]): Unit = {
    def sum(a: Int, b: Int, c: Int) = a + b + c
    def sum2 = sum(2, _: Int, 4)
    println(sum2(4))
  }
}
