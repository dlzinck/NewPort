import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactServiceTest {

    // Tests a contact can be added successfully
    @Test
    public void testAddContact() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        assertDoesNotThrow(() -> service.addContact(contact));
    }

    // Tests adding a duplicate contact ID throws an exception
    @Test
    public void testAddDuplicateContactId() {
        ContactService service = new ContactService();
        Contact contact1 = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");
        Contact contact2 = new Contact("10001", "Augustus", "Rome", "0987654321", "200 Empire Road");

        service.addContact(contact1);

        assertThrows(IllegalArgumentException.class, () -> {
            service.addContact(contact2);
        });
    }

    // Tests adding a null contact throws an exception
    @Test
    public void testAddNullContact() {
        ContactService service = new ContactService();

        assertThrows(IllegalArgumentException.class, () -> {
            service.addContact(null);
        });
    }

    // Tests deleting an existing contact works
    @Test
    public void testDeleteContact() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);

        assertDoesNotThrow(() -> service.deleteContact("10001"));
    }

    // Tests deleting a contact with a null ID throws an exception
    @Test
    public void testDeleteContactWithNullId() {
        ContactService service = new ContactService();

        assertThrows(IllegalArgumentException.class, () -> {
            service.deleteContact(null);
        });
    }

    // Tests deleting a contact that does not exist throws an exception
    @Test
    public void testDeleteContactThatDoesNotExist() {
        ContactService service = new ContactService();

        assertThrows(IllegalArgumentException.class, () -> {
            service.deleteContact("99999");
        });
    }

    // Tests updating first name works
    @Test
    public void testUpdateFirstName() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);
        service.updateFirstName("10001", "Scipio");

        assertEquals("Scipio", contact.getFirstName());
    }

    // Tests updating last name works
    @Test
    public void testUpdateLastName() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);
        service.updateLastName("10001", "Augustus");

        assertEquals("Augustus", contact.getLastName());
    }

    // Tests updating phone works
    @Test
    public void testUpdatePhone() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);
        service.updatePhone("10001", "0987654321");

        assertEquals("0987654321", contact.getPhone());
    }

    // Tests updating address works
    @Test
    public void testUpdateAddress() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);
        service.updateAddress("10001", "200 Empire Road");

        assertEquals("200 Empire Road", contact.getAddress());
    }

    // Tests updating a contact with a null ID throws an exception
    @Test
    public void testUpdateWithNullId() {
        ContactService service = new ContactService();

        assertThrows(IllegalArgumentException.class, () -> {
            service.updateFirstName(null, "Scipio");
        });
    }

    // Tests updating a contact that does not exist throws an exception
    @Test
    public void testUpdateContactThatDoesNotExist() {
        ContactService service = new ContactService();

        assertThrows(IllegalArgumentException.class, () -> {
            service.updateLastName("99999", "Augustus");
        });
    }

    // Tests invalid updated phone data throws an exception
    @Test
    public void testUpdateInvalidPhone() {
        ContactService service = new ContactService();
        Contact contact = new Contact("10001", "Julius", "Caesar", "1234567890", "100 Rome Street");

        service.addContact(contact);

        assertThrows(IllegalArgumentException.class, () -> {
            service.updatePhone("10001", "111");
        });
    }
}