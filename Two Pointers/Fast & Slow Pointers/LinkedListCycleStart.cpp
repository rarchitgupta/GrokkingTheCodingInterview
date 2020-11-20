int calculateLength(ListNode *slow)
{
    int cycleLength = 0;
    ListNode *cur = slow;
    do
    {
        cur = cur->next;
        cycleLength++;
    } while (cur != slow);

    return cycleLength;
}

ListNode *findLinkedListCycleStart(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    int k;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            k = calculateLength(slow);

        slow = slow->next;
        fast = fast->next->next;
    }

    slow = head;
    fast = head;

    while (k > 0)
    {
        fast = fast->next;
        k--;
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
