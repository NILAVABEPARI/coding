import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class PreparedStatementDemo {
    public static void main(String[] args) throws Exception {
        String url = "jdbc:postgresql://localhost:5432/Demo";
        String userName = "postgres";
        String password = "HART";
        String sql = "insert into public.student values (?, ?, ?)";

        // new user details
        String sname = "Jasmine";
        int marks = 52;
        int sid = 101;

        Connection con = DriverManager.getConnection(url, userName, password);
        System.out.println("Connection Established");

        PreparedStatement st = con.prepareStatement(sql);
        st.setString(1, sname);
        st.setInt(2, marks);
        st.setInt(3, sid);
        st.execute();
        con.close();
        System.out.println("Connection close");
    }
}
