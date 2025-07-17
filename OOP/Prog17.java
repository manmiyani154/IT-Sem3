class InvalidEmailAddressException extends Exception {
    InvalidEmailAddressException(String msg) {
        super(msg);
    }
}

class InvalidTelephoneNumberException extends Exception {
    InvalidTelephoneNumberException(String msg) {
        super(msg);
    }
}

public class Prog17 {
    public static void main(String[] args) {
        String email = "useremail.com";
        String phone = "98765432101";

        try {
            if (!email.contains("@") || !email.contains("."))
                throw new InvalidEmailAddressException("Invalid Email");

            if (phone.length() > 10)
                throw new InvalidTelephoneNumberException("Invalid Phone");

            System.out.println("Valid Data");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
