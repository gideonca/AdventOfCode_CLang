import java.security.MessageDigest
import scala.annotation.tailrec

object Day4 {
    def main(args: Array[String]): Unit = {
        val hashInput = "ckczppom"
        val number = findLowestNumber(hashInput, "00000")
        println(s"The lowest positive number with 5 leading zeroes is: $number")
        val number2 = findLowestNumber(hashInput, "000000")
        println(s"The lowest positive number with 6 leading zeroes is: $number2")
    }

    def findLowestNumber(hashInput: String, leadingZeroes: String): Int = {
        val md = MessageDigest.getInstance("MD5")
        val sb = new StringBuilder

        @tailrec
        def loop(number: Int): Int = {
            sb.clear()
            sb.append(hashInput).append(number)
            val hash = md5(sb.toString, md)
            if (hash.startsWith(leadingZeroes)) { number }
            else loop(number + 1)
        }

            loop(1)
        }

    def md5(s: String, md: MessageDigest): String = {
        md.update(s.getBytes)
        val digest = md.digest()
        digest.map("%02x".format(_)).mkString
    }
}