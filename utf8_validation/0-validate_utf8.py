#!/usr/bin/python3
"""
UTF-8 Validation module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: List of integers representing bytes

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks to check the most significant bits
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    for num in data:
        # Get only the 8 least significant bits
        byte = num & 0xFF

        if num_bytes == 0:
            # Determine how many bytes in the UTF-8 character
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask = mask >> 1

            # 1 byte character (0xxxxxxx)
            if num_bytes == 0:
                continue

            # Invalid scenarios:
            # - More than 4 bytes
            # - 1 byte starting with 10xxxxxx (continuation byte alone)
            if num_bytes == 1 or num_bytes > 4:
                return False

        else:
            # Check if current byte is a valid continuation byte (10xxxxxx)
            if not (byte & mask1 and not (byte & mask2)):
                return False

        # Decrement the number of bytes to process
        num_bytes -= 1

    # All characters must be complete
    return num_bytes == 0
