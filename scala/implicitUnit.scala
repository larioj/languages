object Main {
  def notReturned(): Unit = "hello"
  def notReturned2() {"world"}
  def returned() = {"world"}
  def returned2(): String = "hello"

  def main(args: Array[String]): Unit = {
    println(notReturned2)
    println(notReturned)
    println(returned2)
    println(returned)
  }
}
