import java.util.ArrayList;

public class ContactService {
    // Stores all contacts in memory
    private final ArrayList<Contact> contacts = new ArrayList<>();

    // Adds a contact only if the contact ID is unique
    public void addContact(Contact contact) {
        // Check if contact is null
        if (contact == null) {
            throw new IllegalArgumentException("Contact cannot be null");
        }

        // Check for duplicate contact ID
        for (Contact existingContact : contacts) {
            if (existingContact.getContactId().equals(contact.getContactId())) {
                throw new IllegalArgumentException("Contact ID must be unique");
            }
        }

        contacts.add(contact);
    }

    // Deletes a contact by contact ID
    public void deleteContact(String contactId) {
        Contact contactToDelete = findContactById(contactId);
        contacts.remove(contactToDelete);
    }

    // Updates the first name for a contact with the given ID
    public void updateFirstName(String contactId, String firstName) {
        Contact contact = findContactById(contactId);
        contact.setFirstName(firstName);
    }

    // Updates the last name for a contact with the given ID
    public void updateLastName(String contactId, String lastName) {
        Contact contact = findContactById(contactId);
        contact.setLastName(lastName);
    }

    // Updates the phone number for a contact with the given ID
    public void updatePhone(String contactId, String phone) {
        Contact contact = findContactById(contactId);
        contact.setPhone(phone);
    }

    // Updates the address for a contact with the given ID
    public void updateAddress(String contactId, String address) {
        Contact contact = findContactById(contactId);
        contact.setAddress(address);
    }

    // Finds and returns a contact by ID
    private Contact findContactById(String contactId) {
        // Check if contactId is null
        if (contactId == null) {
            throw new IllegalArgumentException("Contact ID cannot be null");
        }

        for (Contact contact : contacts) {
            if (contact.getContactId().equals(contactId)) {
                return contact;
            }
        }

        throw new IllegalArgumentException("Contact ID not found");
    }
}