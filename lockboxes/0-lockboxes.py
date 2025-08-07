#!/usr/bin/python3
"""
Module pour déterminer si toutes les boîtes peuvent être ouvertes
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.

    Args:
        boxes: Liste de listes où chaque liste contient les clés
               que cette boîte contient

    Returns:
        True si toutes les boîtes peuvent être ouvertes, False sinon
    """
    if not boxes:
        return True

    n = len(boxes)
    # Ensemble des boîtes ouvertes (commence avec la boîte 0)
    opened = set([0])
    # Pile des boîtes à explorer
    stack = [0]

    while stack:
        current_box = stack.pop()

        # Récupérer toutes les clés de la boîte actuelle
        for key in boxes[current_box]:
            # Si la clé correspond à une boîte valide et non encore ouverte
            if isinstance(key, int) and 0 <= key < n and key not in opened:
                opened.add(key)
                stack.append(key)

    # Vérifier si toutes les boîtes ont été ouvertes
    return len(opened) == n
