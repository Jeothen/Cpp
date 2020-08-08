// P01 (*) Find the last element of a list.
//     Example:
//     scala> last(List(1, 1, 2, 3, 5, 8))
//     res0: Int = 8

// The start of the definition of last should be
//     def last[A](l: List[A]): A = ...
// The `[A]` allows us to handle lists of any type.


object p1 {
  def lastnum[A](lis : List[A]) : A = lis.last

  def main(args: Array[String]): Unit = {
    val nums: List[Int] = List(1,2,3,5,7)
    println(lastnum(nums))
  }
}
