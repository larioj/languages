object slain {
  def main(args: Array[String]) = {
    val s = "hello".groupBy(c => c).map { case (k, v) => k -> v.length }
    println(s)
  }
}
