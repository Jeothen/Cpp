// P05 (*) Reverse a list.
// scala> reverse(List(1, 1, 2, 3, 5, 8))
//  res0: List[Int] = List(8, 5, 3, 2, 1, 1)

object p5 {
  def reverse[A] (lis: List[A])= lis.reverse

  //:::반대로 삼중 콜론 연산자 는 List객체 의 메서드 일 뿐이며 해당 이름을 가진 클래스가 없다
  //   전체 목록을 다른 목록 앞에 추가하고 (목록에 결합), : 로 끝나는 것을 오른쪽에 연관
  def recursive_reverse[A] (lis: List[A]): List[A] = lis match {
//    case h :: tail => recursive_reverse(tail) ::: List(h)
    case ::(h,tail) => recursive_reverse(tail) ::: List(h)
    case Nil => Nil
  }

  def reverse2[A] (lis:List[A]): List[A] = {
    def _reverse (res: List[A], rem: List[A]) : List[A] = rem match{
      case Nil => res
      case h :: tail => _reverse(h::res, tail)
    }
    _reverse(Nil,lis)
  }

  def fold_reverse[A] (lis:List[A]): List[A] = lis.foldLeft(List[A]()) {
    (r,h) => h::r
  }

  def main(args: Array[String]): Unit = {
    val nums: List[Int] = List(1,1,2,3,5,8)
    println(reverse(nums))
    println(recursive_reverse(nums))
    println( List(1,2,3).:::(List(4,2,3))) // .
    println( List(1,2,3):::(List(4,2,3)))
    println(fold_reverse(nums))


  }
}
