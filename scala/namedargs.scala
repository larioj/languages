object Main {
  def main(args: Array[String]): Unit = {
    def time(hour: Int, minute: Int, second: Int) = println(hour+":"+minute+":"+second)
    time(2, 40, 0)
    time(hour = 2, second = 40, minute = 20)
    //time(2, 40, minute = 20)
  }
}
