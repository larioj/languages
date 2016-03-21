object Main {
  def main(args: Array[String]): Unit = {
    var f = new foo()
    f.sum = 10
    println(10)
    println(f.addSum(20))
    println("hoh")
  }

  class foo {
    var sum = 0

    def addSum(a: Int): Int = {
      return sum + a
    }
  }
}

