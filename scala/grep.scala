object Main {
  def main(args: Array[String]): Unit = {
    def fileLines(file: java.io.File) =
      scala.io.Source.fromFile(file).getLines().toList

    val files = (new java.io.File(".")).listFiles

    for (
      file <- files;
      line <- fileLines(file);
      trimmed = line.trim
    ) println(trimmed)
  }
}
