import java.security.MessageDigest

object Day4 {
    def main(args: Array[String]): Unit = {
        var hashInput = "ckczppom"
        var number = 1
        var hash = ""

        while( true ) {
            val combined = hashInput + number.toString
            hash = md5(combined)

            if (hash.startsWith("00000")) {
                println("Part 1: " + number)
                if (hash.startsWith("000000")) {
                    println("Part 2: " + number)
                    return
                }
            }
            number+=1
        }
    }

    def md5(s: String): String = {
        val md = MessageDigest.getInstance("MD5")
        md.digest(s.getBytes).map("%02x".format(_)).mkString
    }
}