using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float moveSpeed;
    public int Score;
    public GameObject bullet1;
    public GameObject bullet2;
    public GameObject failPannel;
    public GameObject eneSpawn;
    public GameObject itemSpawn;

    public int bulletPower;
    public int Life;

    // Start is called before the first frame update
    void Start()
    {
        bulletPower = 0;
        Life = 3;
    }

    // Update is called once per frame
    void Update()
    {
        Move();
        Shoot();

        if (Life <= 0)
        {
            Time.timeScale = 0;
            failPannel.SetActive(true);
            eneSpawn.SetActive(false);
            itemSpawn.SetActive(false);
        }
    }

    void Move()
    {
        float keyHorizontal = Input.GetAxis("Horizontal");
        float keyVertical = Input.GetAxis("Vertical");

        transform.Translate(Vector3.right * this.moveSpeed * Time.smoothDeltaTime * keyHorizontal, Space.World);
        transform.Translate(Vector3.forward * this.moveSpeed * Time.smoothDeltaTime * keyVertical, Space.World);
    }

    void Shoot()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (bulletPower == 0)
                Instantiate(bullet1, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
            else
                Instantiate(bullet2, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Enemy")
        {
            Life--;
        }
        if (other.tag == "PowerUpItem")
        {
            bulletPower++;
        }
        if (other.tag == "LifeItem")
        {
            Life++;
        }
    }
}
