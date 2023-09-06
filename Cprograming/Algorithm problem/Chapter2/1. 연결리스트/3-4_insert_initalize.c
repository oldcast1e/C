void Initialize(ListNode *head){
    
    ListNode* ListNode1 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode1->next = head->next;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    head->next = ListNode1;
    ListNode1->data = 'A';//node1의 데이터 업데이드

    ListNode* ListNode2 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode1->next = ListNode2;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    ListNode2->data = 'B';//node1의 데이터 업데이드

    ListNode* ListNode3 = (ListNode*)malloc(sizeof(ListNode)); //node1 이라는 새로운 노드를 새로 할당
    ListNode2->next =ListNode3;//node1의 꼬리를 (기존)헤드의 꼬리로 연결
    ListNode3->data = 'D';//node1의 데이터 업데이드
}