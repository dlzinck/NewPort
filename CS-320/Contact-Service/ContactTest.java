import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactTest {

    // Tests that a valid contact is created correctly
    @Test
    public void testValidContactCreation() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");

        assertEquals("12345", contact.getContactId());
        assertEquals("Alexander", contact.getFirstName());
        assertEquals("Caesar", contact.getLastName());
        assertEquals("1234567890", contact.getPhone());
        assertEquals("123 Empire Road", contact.getAddress());
    }

    // Contact ID tests
    @Test
    public void testContactIdCannotBeNull() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact(null, "Alexander", "Caesar", "1234567890", "123 Empire Road");
        });
    }

    @Test
    public void testContactIdTooLong() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345678901", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        });
    }

    // First name tests
    @Test
    public void testFirstNameCannotBeNull() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", null, "Caesar", "1234567890", "123 Empire Road");
        });
    }

    @Test
    public void testFirstNameTooLong() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "AlexanderTheGreat", "Caesar", "1234567890", "123 Empire Road");
        });
    }

    // Last name tests
    @Test
    public void testLastNameCannotBeNull() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", null, "1234567890", "123 Empire Road");
        });
    }

    @Test
    public void testLastNameTooLong() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", "VeryLongLastName", "1234567890", "123 Empire Road");
        });
    }

    // Phone tests
    @Test
    public void testPhoneCannotBeNull() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", "Caesar", null, "123 Empire Road");
        });
    }

    @Test
    public void testPhoneMustBeExactly10Digits() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", "Caesar", "12345", "123 Empire Road");
        });
    }

    // Address tests
    @Test
    public void testAddressCannotBeNull() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", "Caesar", "1234567890", null);
        });
    }

    @Test
    public void testAddressTooLong() {
        assertThrows(IllegalArgumentException.class, () -> {
            new Contact("12345", "Alexander", "Caesar", "1234567890",
                    "1234567890123456789012345678901");
        });
    }

    // Setter tests (valid updates)
    @Test
    public void testSetValidFirstName() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        contact.setFirstName("Napoleon");
        assertEquals("Napoleon", contact.getFirstName());
    }

    @Test
    public void testSetValidLastName() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        contact.setLastName("Bonaparte");
        assertEquals("Bonaparte", contact.getLastName());
    }

    @Test
    public void testSetValidPhone() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        contact.setPhone("0987654321");
        assertEquals("0987654321", contact.getPhone());
    }

    @Test
    public void testSetValidAddress() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        contact.setAddress("456 Battle Street");
        assertEquals("456 Battle Street", contact.getAddress());
    }

    // Setter tests (invalid updates)
    @Test
    public void testSetFirstNameToNull() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setFirstName(null);
        });
    }

    @Test
    public void testSetInvalidPhone() {
        Contact contact = new Contact("12345", "Alexander", "Caesar", "1234567890", "123 Empire Road");
        assertThrows(IllegalArgumentException.class, () -> {
            contact.setPhone("111");
        });
    }
}