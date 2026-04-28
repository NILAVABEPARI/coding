import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class JdbcInsertUpdate {
    public static void main(String[] args) throws Exception {

        String url = "jdbc:postgresql://localhost:5432/Demo";
        String userName = "postgres";
        String password = "HART";
        String sql = "update student set sname='Max' where sid = 5";

        Connection con = DriverManager.getConnection(url, userName, password);
        System.out.println("Connection Established");

        Statement st = con.createStatement();
        st.execute(sql);
        con.close();
        System.out.println("Connection close");
    }
}
