object Main {
  def main(args: Array[String]): Unit = {
    def cow(a: String = "moo! ") = println(a)
    cow()
    cow("hello good sir.")
  }
}
