using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QuestObject : MonoBehaviour
{
    public static QuestObject manager;

    // Awake : ���� Value ����
    // Start : ������ Load / Create
    private void Awake()
    {
        DontDestroyOnLoad(gameObject);  // �� ������Ʈ�� ���� ����ǵ� ���ŵ��� �ʴ´�

        if (manager == null)    // �Ҵ�Ǿ� ���� �ʴٸ�
        {
            manager = this;
        }
        else if(manager != this)        // ���� �Ҵ�Ǿ� �ִ� ������Ʈ���ƴ϶��
        {
            Destroy(gameObject);        // NAGA
        }

        isClear = false;
        objectIndex = 0;
        questSubIndex = 0;
    }

    questJsonData JsonData;         // Quest Json Data
    bool isClear;                   // Quest isClear bool var
    questData currentQuest;
    int questSubIndex;       // Quest sub Index var;
    int objectIndex;                // Quest Object Index var;
    //GameObject tutorialImage;

    // Start is called before the first frame update
    //public List<Material> NPC_Plane_Marks;//NPC ����Ʈ ��ũ �߰�
    void Start()
    {
        if (json.FileExist(Application.dataPath, "quests"))                                      // Quest ������ ������ ��
        {
            JsonData = json.LoadJsonFile<questJsonData>(Application.dataPath, "quests");   // Quest Load
            Debug.Log("Load Complete : " + JsonData.questList[0].npcName);
        }
        else                                                                                    // Quest ������ �������� ���� ��
        {
            //JsonData = new questJsonData();                // new Class
            //JsonData.questList[0].Log();
            //questJsonData.questList = new List<questData>();    // new List
            //questJsonData.questIndex = -1;                      // Quest index -1�� ����

            questJsonData temp = new questJsonData();

            //foreach(var quest in JsonData.questList)
            //{
            //    temp.questList.Add(quest);
            //}


            string questStr = json.ObjectToJson(temp);        // ToString

            Debug.Log(questStr);

            json.CreateJsonFile(Application.dataPath, "quests", questStr);  // Create Json FIle
        }

        currentQuest = JsonData.questList[JsonData.questIndex];
        MissionSet();
        if (JsonData.questIndex == 0)
            UI_Control.Inst.Mission.misssionSet("Ʃ�丮��", "villagerA���� ���� �Žÿ�");
        //tutorialImage = GameObject.Find("TutorialImage");
    }
    int tmp;//�ε��� Ȯ�ο� �ӽ� ����
    // Update is called once per frame
    void Update()
    {
        tmp = JsonData.questIndex;//�ε��� Ȯ�ο� �ӽ� ����
        //if (JsonData.questIndex == 0 && Input.anyKeyDown)
        //{
        //    tutorialImage.SetActive(false);
        //    UI_Control.Inst.Mission.misssionSet("Ʃ�丮��", "villagerA���� ���� �Žÿ�");
        //}
        // ����Ʈ ���� ���� Ȯ��
        switch (currentQuest.questObject[questSubIndex])
        {
            case QuestKind.management:
                //Debug.Log("Developer's Kind");
                //UI_Control.Inst.Mission.misssionSet("Ʃ�丮��", "�ӽ��ؽ�Ʈ. ����Ʈ ���� �ε�.");
                //SetNextQuest();
                break;
            default:
                CheckQuestCount();
                break;
        }
        // ���� quest text print
        if (Input.GetKeyDown(KeyCode.Tab))//����Ʈ �׽�Ʈ�� �ӽ� �ڵ�
        {
            itemData tempItem = new itemData();
            tempItem.itemID = currentQuest.objectId[questSubIndex];
            tempItem.xSize = tempItem.ySize = 1f;
            System.Array.Resize(ref tempItem.tag, 2);
            tempItem.itemName = "����Ʈ ����";
            tempItem.tag[0] = "food";
            tempItem.tag[1] = "cooked";
            Vector2 itemPos = inventoryObject.Inst.emptyCell(1f, 1f);
            inventoryObject.Inst.itemGet(1f, 1f, itemPos.x, itemPos.y, tempItem);
        }

    }

    public questJsonData GetQuestData()
    {
        if (JsonData == null) return null;      // Except
        return JsonData;
    }

    public int GetObjectId()
    {
        return currentQuest.objectId[questSubIndex];
    }

    public Vector3 GetPosition()
    {
        Debug.Log("���� ��ġ : " + currentQuest.position[questSubIndex].x);
        return currentQuest.position[questSubIndex];
    }

    public int GetObjectIndex()                                 // Get ObjectIndex Var Func
    {
        return objectIndex;
    }


    public void SetObjectIndex(int idx)                         // Set ObjectIndex Var Func
    {
        objectIndex = idx;
        MissionSet();
    }

    void CheckQuestCount()                                      // Quest Index Check Func
    {
        switch (currentQuest.questObject[questSubIndex])//����Ʈ ������ ���� �ε��� ���� �ٸ��� ó��
        {
            case QuestKind.interactive:
                break;
            case QuestKind.kill:
            case QuestKind.cook:
            case QuestKind.hunt:
                if (objectIndex >= currentQuest.objectCnt[questSubIndex])
                {
                    SetIsClear(true);
                }
                break;
            case QuestKind.management:
            case QuestKind.spot:
                if (objectIndex == currentQuest.objectCnt[questSubIndex])
                {
                    SetIsClear(true);
                }
                break;
            default:
                break;
        }
        //if (objectIndex == currentQuest.objectCnt[questSubIndex])
        //{
        //    SetIsClear(true);
        //}
    }

    //void SetCookCount()                                         // �丮 ���� Ȯ�� �Լ�
    //{
    //    if (objectIndex == currentQuest.objectVar)
    //        SetIsClear(true);
    //}

    //void SetHuntCount()                                         // ���� ī��Ʈ Ȯ�� �Լ�
    //{
    //    if (objectIndex == currentQuest.objectVar)
    //        SetIsClear(true);
    //}

    //void SetInteractiveCount()                                  // ��ȣ�ۿ� ���� Ȯ�� �Լ�
    //{
    //    if (objectIndex == currentQuest.objectVar)
    //        SetIsClear(true);
    //}

    public void SetNextQuest()                                         // ���� ����Ʈ �̵� �Լ�
    {
        JsonData.questIndex += 1;                               // Quest Index++
        isClear = false;
        questSubIndex = 0;
        SetObjectIndex(0);
        if (JsonData.questList.Count <= JsonData.questIndex)
        {
            //GameObject.Find(currentQuest.npcName).GetComponent<NPC>().SetIndex(100);
            UI_Control.Inst.Mission.misssionSet("", "");
            return;
        }
        currentQuest = JsonData.questList[JsonData.questIndex]; // Update Current Quest
        MissionSet();
        //GameObject.Find(currentQuest.npcName).GetComponent<NPC>().SetIndex(GameObject.Find(currentQuest.npcName).GetComponent<NPC>().GetIndex() + 1);
        //NPC ��ȭ �ε��� �����Լ�, ���� ��ġ�� NPC ��ũ��Ʈ ���� �̵�
        GameObject.Find("GameManager").GetComponent<SetPositionParticle>().InitializeVariable();    // ��ƼŬ ��ġ ����
    }

    public bool GetIsClear()
    {
        return isClear;
    }

    public void SetIsClear(bool idx)
    {
        isClear = idx;

        if (idx)
        {
            if(questSubIndex != currentQuest.objectId.Count - 1)     // ���� ����Ʈ�� �������� �ƴ� ��
            {
                questSubIndex++;
                isClear = false;
                SetObjectIndex(0);                  // ���� �ʱ�ȭ
            }
            else
            {
                if (currentQuest.npcName == "none")//NPC���� �����ʰ� ����Ʈ�� Ŭ����Ǵ� ���
                    SetNextQuest();
                else
                    UI_Control.Inst.Mission.misssionSet(UI_Control.Inst.Mission.GetMissionTitle(), currentQuest.npcName + "���� ���ÿ�");
            }
        }
    }
    public string GetNPCName()
    {
        return currentQuest.npcName;
    }

    public void MissionSet()
    {
        string missionTitle = "";
        string missionText = "";
        string questPurpose = "";
        questPurpose = " " + currentQuest.objectCnt[questSubIndex].ToString();//������ ���κ�(��ǥ)
        string questProgress = "(" + objectIndex.ToString() + "/" + questPurpose + ")";//������ ���κ�(����Ʈ �����Ȳ)
        switch (currentQuest.questObject[questSubIndex])//�丮�� ��ȣ�ۿ��� ��� ���⿡�� � �丮 Ȥ�� � ��ȣ�ۿ����� ����
        {
            case QuestKind.kill:
                missionText = "����" + questPurpose + "���� óġ�ϱ�" + questProgress;
                break;
            case QuestKind.hunt:
                missionText = "����" + questPurpose + "���� ����ϱ�" + questProgress;
                break;
            case QuestKind.cook:
                switch (currentQuest.objectId[questSubIndex])//if�� switch������ ����
                {//���� json���� ����Ʈ ���� ������ ����Ʈ�� �����Ͽ� �ش� id�� �´� �̸��� �������� ���� ����
                    case 1000:
                        missionText = "������";
                        break;
                    case 2001:
                        missionText = "�����ֽ���";
                        break;
                    default:
                        missionText = "���� ��ϵǾ� ���� ���� ��������";
                        break;
                }
                missionText += questPurpose + "�� ��ų� �����" + questProgress;
                break;
            case QuestKind.interactive:
                break;
            case QuestKind.spot://Ư�� ��ġ �̵� �κ� �߰�
                missionText = "������ ���ÿ�.";//��ġ ���� �ʿ�
                break;
            default:
                break;
        }
        missionTitle = JsonData.questIndex % 2 == 0 ? "" : "Quest " + ((JsonData.questIndex + 1) / 2).ToString();
        UI_Control.Inst.Mission.misssionSet(missionTitle, missionText);
    }
    public int GetIndex()
    {
        return JsonData.questIndex;
    }
    public QuestKind GetQuestKind()
    {
        return currentQuest.questObject[questSubIndex];
    }
}