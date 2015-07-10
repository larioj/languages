import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class bulk {
	public static int X = 1;
	public static int Y = 2;
	public static int Z = 4;

	public class pointspace {
		public Set<point> points;

		public pointspace() {
			points = new HashSet<point>();
		}
	}

	public class point {
		public int x, y, z;
		public ArrayList<face> faces;
		public point(int x, int y, int z) {
			this.x = x; this.y = y; this.z = z;
			faces = new ArrayList<face>();
		}
		public void addface(face f) {
			faces.add(f);
		}
	}

	public class face {
		public Set<point> points;
		public int plane;
	}

	public static int main(String[] args) {
		return 0;
	}
}
