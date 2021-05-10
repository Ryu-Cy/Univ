using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject obj;
    public GameObject obj2;
    public GameObject obj3;
    public GameObject obj4;
    private GameObject target;
    public Text scoreTxt;

    int randomNum;
    int count = 0;
    public int score = 0;
    
    // Start is called before the first frame update
    void Start()
    {
        float dis = 2.5f;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                randomNum = Random.Range(1, 10);
                if (randomNum%2 == 0)
                {
                    Instantiate(obj, new Vector3(i * dis - dis, j * dis - dis, 0), Quaternion.identity);
                }
                else
                {
                    Instantiate(obj2, new Vector3(i * dis - dis, j * dis - dis, 0), Quaternion.identity);
                }
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            CastRay();
            Debug.Log("MouseClick");
        }

        scoreTxt.text = "" + score;
    }

    void CastRay()
    {
        target = null;
        Vector2 pos = Camera.main.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, 20.0f));
        RaycastHit2D hit = Physics2D.Raycast(pos, Vector2.zero, 0.0f);

        if (hit.collider != null)
        {
            Debug.Log(hit.collider.name);
            Debug.Log(pos);
            target = hit.collider.gameObject;
            Destroy(target);

            if (hit.collider.name == "сrystal 2(Clone)")
            {
                Instantiate(obj3, new Vector3(target.transform.position.x, target.transform.position.y, 0), Quaternion.identity);
                score += 10;
            }
            else
            {
                Instantiate(obj4, new Vector3(target.transform.position.x, target.transform.position.y, 0), Quaternion.identity);
                score -= 10;
            }
        }
    }
}
