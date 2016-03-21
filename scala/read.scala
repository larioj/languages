import scala.io.Source

object Main {
  def main(args: Array[String]): Unit = {
    for (i <- 1 to 10) {
      for (line <- Source.fromFile(args(0)).getLines()) {
        println(line)
      }
    }
  }
}
