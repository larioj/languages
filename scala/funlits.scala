object Main {
  def main(args: Array[String]): Unit = {
    val l = List(1, 2, 3, 4)
    l.foreach(x => println(x))
    l.foreach(println _)
    l.foreach(println(_))
    l.foreach(println)
  }
}
