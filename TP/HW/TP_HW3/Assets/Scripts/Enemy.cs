using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    public float Speed;
    public GameObject fxObj;
    public GameObject fxObj2;

    private float z_Pos;
    private int Life;

    // Start is called before the first frame update
    void Start()
    {
        z_Pos = 0.0f;
        Life = 2;
    }

    // Update is called once per frame
    void Update()
    {
        z_Pos -= 0.2f;
        transform.Translate(0.0f, 0.0f, z_Pos * Speed * Time.deltaTime);

        if (transform.position.z < -10.0f)
            Destroy(gameObject, 0);

        if (Life <= 0)
        {
            Destroy(gameObject, 0);
            GameObject.Find("Player").GetComponent<Player>().Score++;
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Bullet1")
        {
            Life -= 1;
            Destroy(other.gameObject, 0);
            Instantiate(fxObj, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
        }
        if (other.tag == "Bullet2")
        {
            Life -= 2;
            Destroy(other.gameObject, 0);
            Instantiate(fxObj2, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
        }
        if (other.tag == "Player")
        {
            Destroy(gameObject, 0);
        }
    }
}
