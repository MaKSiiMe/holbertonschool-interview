#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


def print_stats(total_size, status_codes):
    """
    Print statistics
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()

            try:
                # Check if line has correct format
                if len(parts) < 7:
                    continue

                # Extract file size (last element)
                file_size = int(parts[-1])
                total_size += file_size

                # Extract status code (second to last element)
                status_code = parts[-2]
                if status_code in status_codes:
                    status_codes[status_code] += 1

            except (ValueError, IndexError):
                # Skip malformed lines
                continue

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Print stats on keyboard interruption
        print_stats(total_size, status_codes)
        raise

    # Print final stats
    print_stats(total_size, status_codes)
