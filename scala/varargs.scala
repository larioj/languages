object Main {
  def main(args: Array[String]): Unit = {
    def echo(args: String*): Unit = args.foreach(println)
    echo("hello", "world")
    val arr = Array[String]("ab", "cd", "ef")
    echo(arr: _*)
  }
}
