object Main {
  def main(args: Array[String]): Unit = {
    val files = (new java.io.File(".")).listFiles
    for (
      file <- files if file.isFile if file.getName.endsWith(".scala")
    ) println(file)
  }
}
