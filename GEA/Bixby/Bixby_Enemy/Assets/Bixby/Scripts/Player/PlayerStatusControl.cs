using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerStatusControl : ElementControl, IDamgeable
{
    public const float GravityForce = 30.0f;

    public float MyStartingHealth = 100.0f;
    public float Health;
    public float MyStartingStamina = 100.0f;
    public float Stamina;

    protected bool isHitted;
    public bool Dead;
    public float DealtDamage;

    public float DashStaminaAmount = 20.0f;
    public float RunStaminaAmount = 10.0f;
    public float SwimStaminaAmount = 10.0f;
    public float ChargeAttackStaminaAmount = 10.0f;

    protected bool isDashed;
    public float DashDistance = 5.0f;

    public float Speed = 5.0f;
    public float SwimSpeed = 4.0f;
    public float RunSpeed = 10.0f;
    public float DashSpeed = 20.0f;
    public float MyCurrentSpeed;
    public float JumpPower = 5.0f;

    public float ShootDistance = 50f;
    public float SwitchToChargeTime = 2.0f;
    public float FireRate = 0.25f;

    protected float rotationSpeed = 45.0f;
    protected float nextFire = 0.0f;

    protected override void Start()
    {
        base.Start();
        Health = MyStartingHealth;
        Stamina = MyStartingStamina;
        MyCurrentSpeed = Speed;
        isDashed = false;
    }

    public virtual void TakeHit(float damage)
    {
        isHitted = true;
        Health -= damage;
        DealtDamage = Mathf.Round(damage * 10) * 0.1f;
        if (Health <= 0 && !Dead)
        {
            die();
        }
    }

    // 건드린 부분
    public virtual void TakeElementHit(float damage, ElementType enemyElement)
    {
        isHitted = true;
        setEnemyElement(enemyElement); // 이렇게 EnemyElement로 바꿔서 쓰거나 enemyElement그대로 써도 될듯.
        float curDamage = attackedOnNormal(damage);

        // 처음에 빈 stack에서 peek하려다보니 문제가 생기는 것 같음. 아닐 수도 ㅎ
        // if (EnemyElement != ElementType.NONE && EnemyElement != ElementStack.Peek())
        // {
        //     this.ElementStack.Push(EnemyElement);
        // }
        Health -= curDamage;
        DealtDamage = Mathf.Round(curDamage * 10) * 0.1f;
        if (Health <= 0 && !Dead)
        {
            die();
        }
    }

    public virtual void StaminaUse(float amount)
    {
        Stamina -= amount;
    }

    public virtual void StaminaTickUse(float amount)
    {
        Stamina -= Time.deltaTime * amount;
    }

    public virtual void StaminaRegerenate()
    {
        if (Stamina != MyStartingStamina)
        {
            Stamina += Time.deltaTime * 10f;
        }

        if (Stamina > MyStartingStamina)
        {
            Stamina = MyStartingStamina;
        }
    }

    protected virtual void die()
    {
        Dead = true;
        GameObject.Destroy(gameObject);
    }
}