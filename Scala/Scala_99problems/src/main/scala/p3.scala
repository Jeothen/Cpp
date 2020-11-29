// P03 (*) Find the Kth element of a list.
//     By convention, the first element in the list is element 0.
//
//     Example:
//     scala> nth(2, List(1, 1, 2, 3, 5, 8))
//     res0: Int = 2

object p3 {
  def findkth[A](k:Int, lis:List[A]): A={
    if (k >=0 && k < lis.length) lis(k)
    else throw new NoSuchElementException
  }

  def findkth2[A](k:Int, lis:List[A]): A = {
    try lis(k)
    catch {
      case e : IndexOutOfBoundsException => throw new NoSuchElementException
    }
  }

  def findrecursive[A](k:Int, lis:List[A]): A = k match{
    case 0 => lis.head
    case k if k > 0 =>findrecursive(k-1,lis.tail) // 하나식 재귀
    case _ => throw new NoSuchElementException
  }


  def findrecursive2[A](k:Int, lis:List[A]):A = (k,lis) match{
    case (0, h::_) => h
    case (k, _::tail) if k > 0 => findrecursive2(k-1,tail)
    case _ => throw new NoSuchElementException
  }


  def lastN[A](n:Int,  lis: List[A]): A = {
    def length[A] (lis:List[A]): Int = {
      def lengthN[A](n:Int, lis:List[A]):Int = lis match{
        case Nil => n
        case _::tail => lengthN(n+1,tail)
      }
      lengthN(0,lis)
    }
    def FKth[A](k:Int, lis:List[A]):A = (k,lis) match {
      case (0, h::_) => h
      case (k, _::tail) if k > 0 => FKth(k - 1, tail)
      case _ => throw new NoSuchElementException
    }
    val k = length(lis) - n
    FKth(k,lis)
  }

  def main(args: Array[String]): Unit = {
    val nums : List[Int] = List(1,1,2,3,5,8)
    println(findkth(2,nums))
    println(lastN(4,nums))
  }
}
