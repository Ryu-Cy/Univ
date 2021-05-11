using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour
{
    public GameObject FireCracer;
    public float interval;
    public float range = 50.0f;
    public float range2 = 3.0f;

    // 코루틴
    // Start is called before the first frame update
    IEnumerator Start()
    {
        while (true)
        {
            transform.position = new Vector3(Random.Range(-range, range), Random.Range(-range2, range2), transform.position.z);
            Instantiate(FireCracer, transform.position, transform.rotation);
            yield return new WaitForSeconds(interval);
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}
