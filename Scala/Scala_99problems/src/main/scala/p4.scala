// P04 (*) Find the number of elements of a list.
//     Example:
//     scala> length(List(1, 1, 2, 3, 5, 8))
//     res0: Int = 6

object p4 {
  def length[A](lis:List[A]):Int = {
    lis.length
  }

  def length2[A] (lis:List[A]): Int = {
    def lengthN[A] (n: Int, lis: List[A]) : Int = lis match {
      case Nil => n
      case _::tail =>lengthN(n+1, tail)
    }
    lengthN(0,lis)
  }

  def lengthRecursive[A](lis:List[A]):Int = lis match{
    case Nil => 0
    case h::tail =>  1 + lengthRecursive(tail)
  }

  def flength[A](lis:List[A]) : Int = lis.foldLeft(0){
    (c,_) => c+1 // def foldLeft[B](z:B) (f: (B,A) => B) : B
  }

  def count[A](c:Int, d :A): Int = { c + 1}
  def clength[A](lis:List[A]): Int = {
    lis.foldLeft(0){count}
  }

  def main(args: Array[String]): Unit = {
    val nums: List[Int] = List(1,1,2,3,5,8)
    println(length(nums))
    println(length2(nums))
    println(lengthRecursive((nums)))
    println(flength(nums))
    println(clength(nums))
  }
}
