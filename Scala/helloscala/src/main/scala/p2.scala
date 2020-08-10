// P02 (*) Find the last but one element of a list.
//     Example:
//     scala> penultimate(List(1, 1, 2, 3, 5, 8))
//     res0: Int = 5

object p2 {
  def penultimate[A](lis:List[A]) :
    A = {
      if (lis.isEmpty) throw new NoSuchElementException
      lis.init.last  // init()은 마지막 요소를 제외한 모든 요소를 return
  }
  def penultimateRecursive[A](lis:List[A]): A = lis match{
    case h::_::Nil =>h //  _ : wildcard,  Nil : 끝목록 (정확히 2개의 요소가 있는 경우) mapping 시킴
    case _::tail => penultimateRecursive(tail) // _ : 임의의 값 , tail : 나머지 항목
    case _ => throw new NoSuchElementException // 나머지
  }

/*
  def lastN[A](n: Int, lis:List[A]): A = {
    if (n <= 0 ) throw new IllegalArgumentException
    if (lis.length < n) throw new NoSuchElementException
    lis.takeRight(n).head
  }
*/
  def main(args: Array[String]): Unit = {
    val nums : List[Int] = List(1,1,2,3,5,8)
    println(penultimate(nums))
    println(penultimateRecursive(nums))
  }
}
