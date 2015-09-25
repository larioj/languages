-- Data types via the data keyword
data Temp = Freezing | Cold | Warm | Hot
data Point = Point Int Int Int deriving (Show)
data Shape = Circle Int Int | Square Int Int Int
-- to export the value constructors we can do
-- Shape(..) in the module declaration.

-- Records
data Person = Person
	{ firstName :: String
	, lastName :: String
	, age :: Int
	, phoneNumber :: String
	, flavor :: String
	} deriving (Show)

-- Type parameters
data Possibly a = None | Simply a
-- this constructor takes all possible types.

-- Type synonyms
type Human = Person

-- Recursive data structures
data MyTree a = MyEmptyTree | MyNode a (MyTree a) (MyTree a)

-- Type classes
class TreeLike a where
	treeLike :: a -> Bool

-- Functors can be mapped over.

main = print $ Person {firstName = "Jesus", lastName = "Larios Murillo",
	age = 22, phoneNumber = "2062711216", flavor = "Vanilla"}
